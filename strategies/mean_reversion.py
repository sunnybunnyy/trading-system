import numpy as np

class MeanReversion:
    def __init__(self, window = 100, entry_z = 2.0, exit_z = 0.5):
        self.window = window
        self.entry_z = entry_z
        self.exit_z = exit_z

        self.prices = np.zeros(window)
        self.index = 0
        self.count = 0
        self.position = 0 # 1: long, -1: short, 0: flat

    def on_price(self, price):
        self.prices[self.index] = price
        self.index = (self.index + 1) % self.window
        self.count = min(self.count + 1, self.window)

        if self.count < self.window:
            return 0
        
        mean = self.prices.mean()
        std = self.prices.std()

        if std == 0:
            return 0
        
        z = (price - mean) / std

        # if price is high and we're not long, then go/stay short
        if z > self.entry_z and self.position <= 0:
            self.position = -1
            return -1 # sell
        # if price is low and we're not short, then go/stay long
        elif z < -self.entry_z and self.position >= 0:
            self.position = 1
            return 1 # buy
        # if price has reverted to normal, close open positions
        elif abs(z) < self.exit_z:
            self.position = 0
            return 0

        # hold
        return 0
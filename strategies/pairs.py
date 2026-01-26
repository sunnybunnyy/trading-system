import numpy as np

class Pairs:
    def __init__(self, window = 200):
        self.window = window
        self.x = np.zeros(window)
        self.y = np.zeros(window)
        self.index = 0
        self.count = 0
        self.position = 0

    def on_prices(self, price_x, price_y):
        self.x[self.index] = price_x
        self.y[self.index] = price_y
        self.index = (self.index + 1) % self.window
        self.count = min(self.count + 1, self.window)

        if self.count < self.window:
            return 0

        beta = np.linalg.lstsq(self.x.reshape(-1, 1), self.y)[0][0]
        spread = self.y - beta * self.x

        mean = spread.mean()
        std = spread.std()
        z = (spread[-1] - mean) / std

        if z > 2:
            self.position = -1
            return -1
        elif z < -2:
            self.position = 1
            return 1
        return 0
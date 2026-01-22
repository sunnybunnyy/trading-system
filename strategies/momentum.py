class Momentum:
    def __init__(self, fast = 10, slow = 50):
        self.alpha_fast = 2 / (fast + 1)
        self.alpha_slow = 2 / (slow + 1)
        self.fast_ema = None
        self.slow_ema = None
        self.position = 0

    def on_price(self, price):
        if self.fast_ema is None:
            self.fast_ema = price
            self.slow_ema = price
            return 0
        
        self.fast_ema = self.alpha_fast * price + (1 - self.alpha_fast) * self.fast_ema
        self.slow_ema = self.alpha_slow * price + (1 - self.alpha_slow) * self.slow_ema

        if self.fast_ema > self.slow_ema and self.position <= 0:
            self.position = 1
            return 1
        elif self.fast_ema < self.slow_ema and self.position >= 0:
            self.position = -1
            return -1
        
        return 0
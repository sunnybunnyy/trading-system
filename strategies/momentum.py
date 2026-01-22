class Momentum:
    def __init__(self, fast = 10, slow = 50):
        self.alpha_fast = 2 / (fast + 1)
        self.alpha_slow = 2 / (slow + 1)
        self.fast_ema = None
        self.slow_ema = None
        self.position = 0
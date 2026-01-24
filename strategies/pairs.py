import numpy as np

class Pairs:
    def __init__(self, window = 200):
        self.window = window
        self.x = np.zeros(window)
        self.y = np.zeros(window)
        self.index = 0
        self.count = 0
        self.position = 0

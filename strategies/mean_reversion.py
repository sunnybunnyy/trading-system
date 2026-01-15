import numpy as np

class MeanReversion:
    def __init__(self, window = 100, entry_z = 2.0, exit_z = 0.5):
        self.window = window
        self.entry_z = entry_z
        self.exit_z = exit_z

        self.prices = np.zeros(window)
        self.index = 0
        self.count = 0
        self.position = 0
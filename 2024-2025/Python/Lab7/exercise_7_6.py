# Python Language, Gr.1, LAB7 exercises implementation author: Daniel Szarek

import random

class InfinityIteratorZeroAndOneSequence:
    """Klasa implementująca iterator nieskończony zwracający: 0, 1, 0, 1, 0, 1, ..."""
    def __init__(self):
        self.counter = 0
    
    def __iter__(self):
        return self
    
    def __next__(self):
        result = self.counter
        self.counter = (self.counter + 1) % 2
        return result
    
class RandomNESWValueSequence:
    """Klasa implementująca iterator nieskończony zwracający przypadkowo jedną wartość z ("N", "E", "S", "W")"""
    def __init__(self):
        self.values = ("N", "E", "S", "W")

    def __iter__(self):
        return self
    
    def __next__(self):
        return random.choice(self.values)
    
class InfinityIteratorWeekDaysSequence:
    """Klasa implementująca iterator nieskończony zwracający 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6"""
    def __init__(self):
        self.counter = 0
        self.values = (0, 1, 2, 3, 4, 5, 6,)
    
    def __iter__(self):
        return self
    
    def __next__(self):
        result = self.values[self.counter]
        self.counter = (self.counter + 1) % 7
        return result

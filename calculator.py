from PyQt5 import QtWidgets
from ui_calculator import Ui_calculator

class CalculatorWindow(QtWidgets.QMainWindow, Ui_Calculator):
  def __init__(self):
    super().__init__()
    self.setupUi(self)
    self.show()
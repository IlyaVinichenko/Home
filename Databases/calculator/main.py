from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
import operator
from calculator import Ui_MainWindow

# Calculator state.
READY = 0
INPUT = 1


class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        super(MainWindow, self).__init__(*args, **kwargs)
        self.setupUi(self)

        for n in range(0, 10):
            getattr(self, 'pushButton_n%s' % n).pressed.connect(lambda v=n: self.input_number(v))
        
        #operations
        self.pushButton_plus.pressed.connect(lambda: self.operation(operator.add))
        self.pushButton_minus.pressed.connect(lambda: self.operation(operator.sub))
        self.pushButton_multiply.pressed.connect(lambda: self.operation(operator.mul))
        self.pushButton_division.pressed.connect(lambda: self.operation(operator.truediv))
        self.pushButton_equally.pressed.connect(self.equals)
        
        #actions
        self.pushButton_clear.pressed.connect(self.reset)

        #run window
        self.reset()
        self.show()

    def display(self):
        self.lcdNumber.display(self.stack[-1])

    def reset(self):
        self.state = READY
        self.stack = [0]
        self.last_operation = None
        self.current_op = None
        self.display()

    def input_number(self, v):
        if self.state == READY:
            self.state = INPUT
            self.stack[-1] = v
        else:
            self.stack[-1] = self.stack[-1] * 10 + v

        self.display()

    def operation(self, op):
        if self.current_op:  # Complete the current operation
            self.equals()

        self.stack.append(0)
        self.state = INPUT
        self.current_op = op

    def equals(self):
        # Support to allow '=' to repeat previous operation
        # if no further input has been added.
        if self.state == READY and self.last_operation:
            s, self.current_op = self.last_operation
            self.stack.append(s)

        if self.current_op:
            self.last_operation = self.stack[-1], self.current_op

            try:
                self.stack = [self.current_op(*self.stack)]
            except Exception:
                self.lcdNumber.display('Err')
                self.stack = [0]
            else:
                self.current_op = None
                self.state = READY
                self.display()

if __name__ == '__main__':
    app = QApplication([])
    app.setApplicationName("Calculator")

    window = MainWindow()
    app.exec_()

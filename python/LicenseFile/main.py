import gui
import sys
import template
from PyQt5.QtWidgets import QApplication, QMainWindow



if __name__ == '__main__':
    #初始化
    global listdir
    listdir=template.readTemplateProducts()
    app = QApplication(sys.argv)
    MainWindow = QMainWindow()
    ui = gui.Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

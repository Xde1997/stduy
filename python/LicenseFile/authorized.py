from PyQt5 import QtGui
from PyQt5.QtWidgets import QButtonGroup


class MyAuthorizedEdit(QtGui.QButtonGroup):
    def __init__(self, parent=None):
        super(QButtonGroup, self).__init__(parent)
        self.setDragEnabled(True)

    def dragEnterEvent(self, event):
        data = event.mimeData()
        urls = data.urls()
        if (urls and urls[0].scheme() == 'file'):
            event.acceptProposedAction()

    def dragMoveEvent(self, event):
        data = event.mimeData()
        urls = data.urls()
        if (urls and urls[0].scheme() == 'file'):
            event.acceptProposedAction()

    def dropEvent(self, event):
        data = event.mimeData()
        urls = data.urls()
        if (urls and urls[0].scheme() == 'file'):
            filepath = str(urls[0].path())[1:]
            filepath = filepath.decode('utf-8')
            self.setText(filepath)

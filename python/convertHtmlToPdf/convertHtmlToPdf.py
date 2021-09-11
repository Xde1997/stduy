import pdfkit
# 导入 xlrd 库
import xlrd
import os
import PyPDF2

options = {
    'page-size': 'Letter',
    'margin-top': '0.75in',
    'margin-right': '0.75in',
    'margin-bottom': '0.75in',
    'margin-left': '0.75in',
    'encoding': "UTF-8",
    'custom-header': [
        ('Accept-Encoding', 'gzip')
    ],
    'cookie': [
        ('cookie-name1', 'cookie-value1'),
        ('cookie-name2', 'cookie-value2'),
    ],
    'no-outline': None
}

filelist = []
for filename in os.listdir('./cpp'):
    if filename.endswith('.pdf'):
        filelist.append(filename)
filelist = sorted(filelist)

path_wkhtmltopdf = r'E:\wkhtmltopdf\bin\wkhtmltopdf.exe'
config = pdfkit.configuration(wkhtmltopdf=path_wkhtmltopdf)


def ProcessXlsFile():
    # 打开刚才我们写入的 test_w.xls 文件
    wb = xlrd.open_workbook("javacn666.xls")
    # 根据 sheet 索引获取内容
    sh1 = wb.sheet_by_index(0)
    # 遍历所有表单内容
    for r in range(sh1.nrows):
        # 输出指定行
        if r >= 1:
            title = sh1.row(r)[1].value
            site = sh1.row(r)[2].value
            # print(title,site)
            filename = "cpp/"+str(title)+".pdf"
            if str(title)+".pdf" in filelist:
                continue
            try:
                pdfkit.from_url(site, filename, configuration=config)
            except:
                continue


def CompliePdf():
    # 创建一个新的pdf
    newPdfFile = PyPDF2.PdfFileWriter()
    # 循环打开每一个pdf文件，将内容添加至新的pdf
    for filename in filelist:
        pdfFile = open('./cpp/' + filename, 'rb')
        pdfObj = PyPDF2.PdfFileReader(pdfFile)
        # 获取页数
        pageNum = pdfObj.numPages

        for num in range(0, pageNum):
            pageContent = pdfObj.getPage(num)
            newPdfFile.addPage(pageContent)
    newFile = open("javacn666.pdf", 'wb')
    newPdfFile.write(newFile)
    newFile.close()


if __name__ == "__main__":
    ProcessXlsFile()
    CompliePdf()

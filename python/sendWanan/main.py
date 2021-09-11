from email.mime.text import MIMEText
from email.header import Header
from smtplib import SMTP_SSL
import requests
import re
import random
from threading import Timer


def get_dirtytalk():
    pageindex = random.randint(1000, 2000)
    try:
        # 找到一个情话网站，分析页面规律
        url = "http://www.ainicr.cn/qh/" + str(pageindex) + ".html"
        # 获取内容
        response = requests.get(url).text
        # 使用正则匹配，匹配情话
        counts = re.findall('<p>(.*?)</p></a>', response)
        # 返回列表中第一条记录
        return counts[0]
    except:
        return r'我爱你，晚安'


# qq邮箱smtp服务器
host_server = 'smtp.qq.com'
# sender_qq为发件人的qq号码
sender_qq = '861529206'
# pwd为qq邮箱的授权码
pwd = 'chdphrpecjkcbbga'
# 发件人的邮箱
sender_qq_mail = '861529206@qq.com'
# 收件人邮箱
receiver = '1481179449@qq.com'

# 邮件标题
mail_title = '爱你'

# ssl登录
smtp = SMTP_SSL(host_server)
# set_debuglevel()是用来调试的。参数值为1表示开启调试模式，参数值为0关闭调试模式
smtp.set_debuglevel(1)
smtp.ehlo(host_server)
smtp.login(sender_qq, pwd)


def send_email():
    try:
        # 邮件的正文内容
        mail_content = get_dirtytalk()
        msg = MIMEText(mail_content, "plain", 'utf-8')

        msg["Subject"] = Header(mail_title, 'utf-8')
        msg["From"] = sender_qq_mail
        msg["To"] = receiver
        smtp.sendmail(sender_qq_mail, receiver, msg.as_string())
        smtp.quit()
        t = Timer(43200, send_email)
        t.start()
    except:
        msg = MIMEText(u'我爱你!', "plain", 'utf-8')

        msg["Subject"] = Header(mail_title, 'utf-8')
        msg["From"] = sender_qq_mail
        msg["To"] = receiver
        smtp.sendmail(sender_qq_mail, receiver, msg.as_string())
        smtp.quit()


if __name__ == "__main__":
    send_email()

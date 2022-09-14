from flask import Flask,jsonify
from requests import get
from re import compile
import config

app = Flask(__name__)
app.config.from_object(config)

#根路径
@app.route('/')
def index():
    return 'Hello,World!'

#传递参数
@app.route('/param/<int:id>')
def getParam(id):
    return 'Hello,'+str(id)

#返回JSON数据
@app.route('/datas')
def getDatas():
    datas = list()
    for i in range(5):
        data = {'id':i,'name':'XXX'+str(i)}
        datas.append(data)
    return jsonify(datas)

#访问静态资源
@app.route('/js')
def getJs():
    return app.url_for('static',filename='test.js')

#设置访问方法
@app.route('/post',methods=['POST'])
def setMethod():
    return 'succeed'

if __name__ == '__main__':
    app.run()
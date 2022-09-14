# Flask
### 1、概述
Flask 是一个使用 Python 编写的轻量级 Web 应用程序框架。Armin Ronacher带领一个名为Pocco的国际Python爱好者团队开发了Flask。 

[Flask 中文教程](https://www.w3cschool.cn/flask_1/)

### 2、快速开发
###### 1）安装 flask
~~~bash
pip install flask
~~~

###### 2）HelloWorld
~~~python
from flask import Flask
app = Flask(__name__)
@app.route('/')
def index():
    return 'Hello,Flask'
if __name__ == '__main__':
    app.run()
~~~

###### 3）绑定路径

在函数名前使用 `@app.route('/path')` 注解

###### 4）参数传递
~~~python
@app.route('/book/<int:id>')
def getBook(id):
    for book in books:
        if id == book['id']:
            return book
    return '未找到id为'+str(id)+'的书籍'
~~~

###### 5）返回 JSON 数据
~~~python
@app.route('/datas')
def getDatas():
    datas = list()
    for data in datas:
        data = {'id': i,'name':'user'+str(i)}
        datas.append(data)
    return flask.jsonify(datas)
    #高版本 flask 可以直接返回 datas ,不需要调用 jsonify
~~~

###### 6）独立链接
有时项目中的路径需要更改，但是不想改其他地方的代码
~~~python
@app.route('/book/<int:id>')
def getBook(id):
    for book in books:
        if id == book['id']:
            return book
    return '未找到id为'+str(id)+'的书籍'
@app.route('/xxx/<int:id>')
def xxx(id):
    return redirect('/book/'+str(id))
~~~
如果修改了 getBook 访问路径，则 xxx 也会被影响，则可以

~~~python
@app.route('/xxx/<int:id>')
def xxx(id):
    return redirect(url_for('getBook',id=id))
~~~

###### 7）指定访问方法
~~~python
@app.route('/login/<int:account>/<int:passwd>',methods=['GET','POST'])
def login(account,passwd):
    pass
~~~

###### 8）内置对象
flask 有内置对象 request，`from flask import request` ,可以通过 request 获取 cookie 等

### 3、项目实战
才刚学有个 P 的项目实战，不过和 SpringBoot 的开发很像，之后如果需要快速搭建一个 App 数据服务器可以考虑使用 flask ，搭建网站的话，还是 boot 吧，可以把 flask 和 Python 通用爬虫结合起来，再见数据库，全网都是我数据库（咳咳，记得来看望我，我怕牢里孤单），兄弟兄弟，爬虫学不学，包吃包住，牢饭免费吃，监狱免费住，还有狱警带你搞项（灰）目（产）【狗头】
# 前端H5-CSS

### 元素类型

行内元素和块元素

- 行内元素：指仅包含自身内容大小的元素，常见的行内元素有 `span、a`  、 `br` 、 `b、strong` 、 `img` 、 `sup、sub` 、`i、em ` 、`u、del` 、`input、textarea、select` 

- 块元素：指占据整行的元素，常见的块元素有`div、p、h1~h6、ul、ol、dl、li、dd、table、hr、blockquote、address、table、menu、pre`，HTML5新增的 `header、section、aside、footer`



部分行内元素可以包含块元素，例如在 `a` 标签中包含 `div` 元素



行内元素 <span style="color:red">不能直接设置宽度和高度</span> ，必要时，可以使用 `display: block;` 进行转换，同理，可以使用 `display: inline;` 将块元素转换成行内元素 ,可以使用 `display: inline-block;` 将元素转换成 <span style="color:red">行内块元素</span> （仍然具有行内元素的特性，但是元素之间会有一小段空格，并且可以设置宽高）

### 文本

| 属性            | 介绍         |
| --------------- | ------------ |
| font-family     | 设置字体系列 |
| font-size       | 字体大小     |
| font-weight     | 字体粗细     |
| font-style      | 字体样式     |
| color           | 文本颜色     |
| text-align      | 文本对其方式 |
| text-decoration | 文本装饰     |
| text-indent     | 文本缩进     |
| line-height     | 行间距       |

给文本添加下划线、删除线、上划线

~~~html
<p>我是一段文本</p>
<style>
	p{
		text-decoration: underline;
		/*underline 下划线、line-through 删除线、overline 上划线*/
	}
</style>
~~~

取消 `a` 标签的下划线

~~~html
<a href="#">我是一个没有下划线的超链接</a>
<style>
	a{
		text-decoration: none;
	}
</style>
~~~

CSS没有提供文字的垂直居中效果，但是我们可以通过行高 `line-height` 等于盒子的高度即可实现文字在竖直方向上居中的效果

### 选择器

- 后代选择器与子代选择器

后代选择器：父代与子代之间使用空格隔开，可以作用于子代、孙代..

子代选择器：父代与子代之间使用 `>` 号连接，仅可以选择直接子代

- <span style="color:red">伪类选择器</span>

| 选择器               | 例子描述                                                     |
| -------------------- | ------------------------------------------------------------ |
| :active              | 匹配被点击的链接                                             |
| :checked             | 匹配处于选中状态的 <input> 元素                              |
| :disabled            | 匹配每个被禁用的 <input> 元素                                |
| :empty               | 匹配任何没有子元素的 <p> 元素                                |
| :enabled             | 匹配每个已启用的 <input> 元素                                |
| :first-child         | 匹配父元素中的第一个子元素 <p>，<p> 必须是父元素中的第一个子元素 |
| :first-of-type       | 匹配父元素中的第一个 <p> 元素                                |
| :focus               | 匹配获得焦点的 <input> 元素                                  |
| :hover               | 匹配鼠标悬停其上的元素                                       |
| :in-range            | 匹配具有指定取值范围的 <input> 元素                          |
| :invalid             | 匹配所有具有无效值的 <input> 元素                            |
| :lang(language)      | 匹配每个 lang 属性值以 "it" 开头的 <p> 元素                  |
| :last-child          | 匹配父元素中的最后一个子元素 <p>， <p> 必须是父元素中的最后一个子元素 |
| :last-of-type        | 匹配父元素中的最后一个 <p> 元素                              |
| :link                | 匹配所有未被访问的链接                                       |
| :not(selector)       | 匹配每个非 <p> 元素的元素                                    |
| :nth-child(n)        | 匹配父元素中的第二个子元素 <p>                               |
| :nth-last-child(n)   | 匹配父元素的倒数第二个子元素 <p>                             |
| :nth-last-of-type(n) | 匹配父元素的倒数第二个子元素 <p>                             |
| :nth-of-type(n)      | 匹配父元素的第二个子元素 <p>                                 |
| :only-of-type        | 匹配父元素中唯一的 <p> 元素                                  |
| :only-child          | 匹配父元素中唯一的子元素 <p>                                 |
| :optional            | 匹配不带 "required" 属性的 <input> 元素                      |
| :out-of-range        | 匹配值在指定范围之外的 <input> 元素                          |
| :read-only           | 匹配指定了 "readonly" 属性的 <input> 元素                    |
| :read-write          | 匹配不带 "readonly" 属性的 <input> 元素                      |
| :required            | 匹配指定了 "required" 属性的 <input> 元素                    |
| :root                | 匹配元素的根元素，在 HTML 中，根元素永远是 HTML              |
| :target              | 匹配当前活动的 #news 元素（单击包含该锚名称的 URL）          |
| :valid               | 匹配所有具有有效值的 <input> 元素                            |
| :visited             | 匹配所有已经访问过的链接                                     |

### 背景

背景颜色使用 `background-color` 属性来指定，背景图片使用 `background-image: url()` 来指定，背景图片默认使用平铺效果（图片被多次复制直到填满整个容器）, `background-repeat` 属性可以指定平铺样式，可选值有 `no-repeat` 、`repeat-x` 、`repeat-y` ，
   ###   import jieba
from jieba import *
print(lcut("国家计算机二级Python考试"))#返回一个列表，每个词语作为一个元素（精确模式）
ls = lcut("国家计算机二级Python考试",cut_all=True)#全模式
print(ls)
ls1 = lcut_for_search("国家计算机二级python考试")#搜索模式，即先进行精确模式，再对其中的长词进行切分
print(ls1)
add_word("Pyhon考试")#添加新词
ls2 = lcut("国家计算机二级Pyhon考试")
print(ls2)



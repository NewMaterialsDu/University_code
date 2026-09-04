import requests
from lxml import etree
import time
url='https://s.weibo.com/top/summary?Refer=top_hot&topnav=1&wvr='
header={'cookie':"SINAGLOBAL=7254774839451.836.1628626364688; SUB=_2AkMWR_ROf8NxqwJRmf8cymjraIt-ygDEieKgGwWVJRMxHRl-yT9jqmUgtRB6PcfaoQpx1lJ1uirGAtLgm7UgNIYfEEnw; SUBP=0033WrSXqPxfM72-Ws9jqgMF55529P9D9WWEs5v92H1qMCCxQX.d-5iG; UOR=,,www.baidu.com; _s_tentry=-; Apache=1090953026415.7019.1632559647541; ULV=1632559647546:8:4:2:1090953026415.7019.1632559647541:1632110419050; WBtopGlobal_register_version=2021092517; WBStorage=6ff1c79b|undefined",
'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.132 Safari/537.36'}
resp = requests.get (url,headers=header)
resp1 = resp.content.decode(encoding='utf-8',errors='ignore')
resp2=etree.HTML(resp1)
title = resp2.xpath('//*[@id="pl_top_realtimehot"]/table/tbody/tr/td/a/text()')
print(time.strftime("%F,%R")+'微博热搜\n')
for i in range(51):
    print (''.join([title[i]]),'\n')
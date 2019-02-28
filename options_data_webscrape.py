from lxml import html
import requests

page = requests.get('http://www.scientific-consultants.com/nnbd.html')
tree = html.fromstring(page.content)
_data = tree.xpath('/html/body/font/pre/text()')

data = _data[0].split("\n")
del data[0]

del data[0]
list(data[0])
print(data[0])

with open('/Users/rss/.spyder-py3/options_data.txt', 'a') as thisFile:
    for element in data:
        thisFile.write(str(element) + "\n")

import requests
import urllib3

url = "https://vovolin.ut18.info/dash/dg1r35/hyK7wTMFaj/DkJJ4kxiL1yWO0gxw1NHa0.ts"
r = requests.get(url)
with open("video.ts","wb") as f :
    f.write(r.content)
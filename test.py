import requests
import urllib3

url = "https://lh5.googleusercontent.com/proxy/MaeL8crTvNDYjueq9TC0AaDnAmqznxtJMptEHT26KIpM78yM7cggj7MEC4r4QnlBrmgc59xydliB5FsoF4YJQ63QIctWTLPZpZJ6C8o00upnLJ9ST0fZ_LLjd8K3_oI23r_S=s0"
r = requests.get(url)
with open("video.ts","wb") as f :
    f.write(r.content)
    print(r.text)
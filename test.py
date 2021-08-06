import requests
import urllib3
import m3u8
url = "https://xemtv24h.com/statics/fmp4/films10/bietdoicamtu2/bietdoicamtu2.m3u8"
r = requests.get(url)
playlist = m3u8.loads(r.text)
print(playlist.data)
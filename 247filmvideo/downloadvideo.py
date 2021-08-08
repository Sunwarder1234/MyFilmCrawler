import requests
import m3u8
re = requests.get("https://xemtv24h.com/statics/fmp4/films10/00vivo/00vivo.m3u8")
playlist = m3u8.loads(re.text)
vidUrl = "https://xemtv24h.com/statics/fmp4/films10/00vivo/{}".format(playlist.data['segments'][0]['uri'])
print(playlist.data['segments'][0]['uri'])
vidRequest = requests.get(vidUrl)
with open("vid1.mp4","wb") as f :
    f.write(vidRequest.content)
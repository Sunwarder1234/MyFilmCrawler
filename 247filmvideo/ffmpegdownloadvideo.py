import os
commandStr = "ffmpeg -headers 'Referer: {header}' -i -loglevel debug https://xemtv24h.com/statics/fmp4/films10/00vivo/00vivo.m3u8 -c copy -bsf:a aac_adtstoasc vidkei"
os.system(commandStr)
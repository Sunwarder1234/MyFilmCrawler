import os

def m3u8download(m3u8url,namefile,currenturl) :
    try : 
        f = open("./247filmvideo/{}".format(namefile+".mp4"),"wb")
        f.close()

        strCommand = "ffmpeg -headers 'Referer: {header}' -i -loglevel debug '{url}' -c copy {path}{name}".format(url=m3u8url,name="output.ts",path="",header=currenturl)
        print(strCommand)
        if(os.path.isfile("./247filmvideo/{}".format(namefile+".mp4"))) : 
            os.system(strCommand)
        else : 
            print("No File")
        
    except : 
        print("Error Download : "+str(namefile))
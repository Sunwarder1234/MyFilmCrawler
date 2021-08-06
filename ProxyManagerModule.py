from browsermobproxy import Server
class ProxyManager :
    __BMP = r"D:\browsermob-proxy-2.1.4\bin\browsermob-proxy.bat"
    def __init__(self):
        self.__server = Server(path=ProxyManager.__BMP,options={"port" : 9080})
        self.__client = None
    def start_server(self) :
        self.__server.start()
        return self.__server
    def start_client(self) :
        self.__client = self.__server.create_proxy()
        return self.__client
    
    @property
    def client(self) :
        return self.__client
    
    @property
    def server(self) :
        return self.__server 



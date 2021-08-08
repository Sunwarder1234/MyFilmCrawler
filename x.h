
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
import selenium
import time
import sys
import json
from bs4 import BeautifulSoup
from selenium.webdriver.chrome.webdriver import WebDriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.remote import webelement
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
from browsermobproxy import Server
from ProxyManagerModule import ProxyManager
import pprint
import urllib.parse
proxy = ProxyManager()
server = proxy.start_server()
client = proxy.start_client()
time.sleep(4)
driver = ""
class PhimmoiCrawler : 
    
    def __init__(self,url) -> None:
        global driver
        global client
        global server
        options = Options()
        
        options.add_argument(f"--proxy-server={client.proxy}")
        options.add_argument('--ignore-ssl-errors=yes')
        options.add_argument('--ignore-certificate-errors')
        options.add_argument('--disable-gpu')
        options.add_argument("--proxy-bypass-list=*247phim*")
        driver = webdriver.Chrome(executable_path=r"C:\Users\Sun\Desktop\chromedriver", chrome_options=options,desired_capabilities=options.to_capabilities())
        driver.get(url)
        time.sleep(4)
    
   
    def interactSiteToAjaxCome(self,count_times):
        global driver
        for i in range(0,count_times) :
           driver.find_element_by_tag_name("body").send_keys(Keys.PAGE_DOWN)
           time.sleep(1)
    def GoIntoFilm(self) : 
        global driver
        global client
        global server
        print("Hi "+sys.argv[1])
        index = sys.argv[1] or input("Type a index to start from")
        films_item = driver.find_elements_by_css_selector("a.movie-item")
        film_links = []
        for i in range(int(index),len(films_item)) :
           film_links.append(films_item.__getitem__(int(i)).get_attribute("href")) 
        for i in range(int(index),len(film_links)) :
           driver.get(film_links[i])
           self.interactSiteToAjaxCome(1)
           filmDatas = self.getFilmsData()

           driver.get(driver.find_element_by_id("btn-film-watch").get_attribute("href"))
           time.sleep(10)
           driver.find_element_by_css_selector("#mediaplayer").click()
           driver.find_element_by_css_selector("#mediaplayer").send_keys(Keys.SPACE)
           

           self.getM3U8File()

    def getM3U8File(self) :
        global client
        global server
        global driver
        print(client.proxy)
        count = 0
        while(True) :      
            try : 
                client.new_har()
                time.sleep(1)
                result = json.dumps(client.har)
                data = json.loads(result)
                print(data['log']['entries'])
                for entry in data['log']['entries'] : 

                    if(str(entry['request']['url']).__contains__("m3u8")) :
                        
                        with open("proxy247phim","a") as f :
                            print(entry['request']['url'])
                            f.writelines(entry['request']['url'])   
                            
                            return 0
                            
            except : 
                x = 1
    def getFilmsData(self) :
        global driver
        filmDatas = {}
        time.sleep(15)
        pageSoup = BeautifulSoup(driver.page_source,"html.parser")
        filmDetailSoup = pageSoup.find(".detail-vod-left .detail")
        filmDatas['category'] = filmDetailSoup.find(".detail-info a:nth-child(2)").get_text()
        filmDatas['publishYear'] = filmDetailSoup.find(".detail-info a::last-child").get_text()
        filmDatas['filmname_vi'] = filmDetailSoup.find(".title-vod:first-child").get_text()
        filmDatas['filmname_eng'] = filmDetailSoup.find(".title-vod:last-child").get_text()
        filmDatas['filmdescription'] = filmDetailSoup.find("div:nth-child(3) p").get_text()
        filmDatas['filmDetail'] = filmDetailSoup.find("div:nth-child(4) div:first-child .more-info").get_text()
        filmDatas['cast'] = filmDetailSoup.find("div:nth-child(4) div:last-child .more-info").get_text()
        
        return filmDatas
        
        
        
        



crawler = PhimmoiCrawler("https://247phim.com/phim/hanh-dong/")
crawler.interactSiteToAjaxCome(6)
crawler.GoIntoFilm()
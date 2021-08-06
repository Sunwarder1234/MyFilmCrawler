from selenium import webdriver
from selenium.webdriver.chrome.options import Options
import selenium
import time
import sys
from selenium.webdriver.common.keys import Keys
options = Options()
driver = webdriver.Chrome(executable_path=r"C:\Users\Sun\Desktop\chromedriver", chrome_options=options)
driver.get("https://phimmoiizz.net/hanh-dong/")

index = sys.argv[0] or input("Type index to start from: ")
for i in range(8) :
    driver.find_element_by_tag_name("body").send_keys(Keys.PAGE_DOWN)
    time.sleep(1)
films_item = driver.find_elements_by_css_selector(".blog-wrapper .post-item")
for i in range(index,len(films_item)) :
    films_item.__getitem__(i).click()
    




import pyautogui
from win32api import GetSystemMetrics
import os
print("SalesMate+ Testing")
pyautogui.FAILSAFE = False
print("Create a database backup directory called 'salesmate+'")
path = "D:/salesmate+"
if not os.path.exists(path):
    os.makedirs(path)

width=GetSystemMetrics(0)
height=GetSystemMetrics(1)
print("Click on bottom left to launch start menu")
pyautogui.click(0,height)
print("Select SalesMate+ Application")
pyautogui.typewrite("SalesMate+")
print("Press Enter key to launch SalesMate+ and wait for 10 sec ")
pyautogui.press("enter",1,10)
print("Press enter key to close tip of the day dialogue box")
pyautogui.press("enter",1,2)
print("Press Alt and F to open file root menu in SalesMate+")
pyautogui.press(['Alt','f'],1,2)
print("Press 'b' to invoke backup folder menu")
pyautogui.press("b",1,2)
print("go to D drive")
pyautogui.press('n',1,1)
print("Press right arrow  key to expand the tree")
pyautogui.press("right",1,2)
print("Goto 'salesmate+' folder")
pyautogui.typewrite("salesmate+")
print("Press enter key to backup data")
pyautogui.press("enter",1,2)
print("Press 'enter' key to close the dialogue window")
pyautogui.press("enter",1,2)



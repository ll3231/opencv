import cv2
import numpy as np
import pickle
import matplotlib.pyplot as plt
 
cap = cv2.VideoCapture(0)
ret,frame = cap.read()
print ret
print frame
cap.release()
cv2.destroyAllWindows()

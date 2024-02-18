import cv2
import mediapipe as mp
import pyautogui


cap=cv2.VideoCapture(0)
hands=mp.solutions.hands.Hands()
drawing_utils=mp.solutions.drawing_utils
connection=mp.solutions.hands.HAND_CONNECTIONS
screen_x,screen_y=pyautogui.size()
x1=y1=x2=y2=0
while True:
    _,frame=cap.read()
    frame=cv2.flip(frame, 1)
    frame_y,frame_x,_=frame.shape
    rgb_cvt=cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    output=hands.process(rgb_cvt)
    multi_hands=output.multi_hand_landmarks
    if multi_hands:
        for hand in multi_hands:
            drawing_utils.draw_landmarks(frame,hand,connection)
            landmarks=hand.landmark
            for id,landmark in enumerate(landmarks):
               x=int(landmark.x*frame_y)
               y=int(landmark.y*frame_x)
               if id==8:
                   point_x=int(screen_y/frame_y*x)
                   point_y=int(screen_x/frame_x*y)
                   pyautogui.moveTo(point_x,point_y)
                   x1=x
                   y1=y
               if id==4:
                   x2=x
                   y2=y
            distance=y2-y1
            # print(distance)
            if distance<=15:
                pyautogui.scroll(-150)
            elif distance>=80:
                pyautogui.scroll(150)
    cv2.imshow("camera",frame)
    if cv2.waitKey(1) & 0xFF==ord('a'):
        break
cap.release()
cv2.destroyAllWindows()
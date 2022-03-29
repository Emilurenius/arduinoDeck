from pynput.keyboard import Key, Listener
import logging
 
def on_press(key):
    global prevKey
    if key != prevKey:
        print(f'Keyboard.press({key});')
        prevKey = key
    # logging.info(str(key))

def on_release(key):
    global prevKey
    if prevKey == key:
        prevKey = None
    print(f'Keyboard.release({key});')
    logging.info(str(key))

if __name__ == '__main__':
    logging.basicConfig(filename=("keylog.txt"), level=logging.DEBUG, format=" %(asctime)s - %(message)s")

    prevKey = None

    with Listener(on_press=on_press,on_release=on_release) as listener :
        listener.join()
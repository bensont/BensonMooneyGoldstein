#This is a really simple main to make is different to how
import Plot.py
import time

def Main():
    #make a plot
    plot = Plot()
    start = time.time()
    running = 0
    while(running<1000):
        if(time.time()-start > 6000):
            plot.get_condition()
            plot.check_condition()
            start = time.time()
            running = running + 1


if __name__ == "__main__":
    main()

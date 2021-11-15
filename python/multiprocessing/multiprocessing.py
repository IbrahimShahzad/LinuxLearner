import multiprocessing
import random

def compute(n):
  """ Returns sum of 10000 random integers"""
  return sum([random.randint(1,100) for i in range(10000)])

def main(n)->None:
  # start N number of workers
  pool = multiprocessing.Pool(processes=n)
  print("Returned results from processes: %s" % pool.map(compute,range(8)))

if __name__=="__main__":
  # Run the main module when file is run directlty
  try:
    n=int(input("Enter number of processes to initiate: "))
  except ValueError:
    # invalid input
    raise ValueError("ValueError exception thrown")
  main(n)

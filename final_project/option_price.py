# -*- coding: utf-8 -*-
"""
Created on Sun Nov 12 17:34:41 2017

@author: Jia
"""

import numpy as np
from scitools.std import plot, figure, hold
def simulate_one_path(T = 100, r = 0.0002, sigma = 0.015):
     #simulate the path of S(t), and return the path as an array
     s = np.zeros(T+1)             #compute stock price for T days
     epsilon = np.random.randn(T+1)            #generate T standard normal random numbers
     s[0] = 100                    #initial stock price is 100
     index_set = range(0, T+1)
     for t in index_set[:T]:       #compute 
          s[t+1] = (1 + r) * s[t] + sigma * s[t] * epsilon[t]
     return s

def find_average(T = 100):            #compute the average from t=1 to t=T
     s = simulate_one_path()
     sm = np.sum(s[1:]) / float(T)
     return sm                     #return the average of the stock price

def asian_option_price(N, r = 0.0002, T = 100, K = 102):
     #compute asian option price based on N simulated averages
     payoffs = np.zeros(N)
     #build an array for values of payoff, and initialize it
     sm = np.zeros(N)
     for i in xrange(N):
          #simulate N times to get an array of values of payoff
          sm[i] = find_average()
          payoffs[i] = max(sm[i] - K, 0)
     expected_payoff = np.sum(payoffs) / float(N)
     #compute the expexted payoff based on N times
     p = (1 + r) ** (-T) * expected_payoff
     #compute asian option price by using the expected payoff
     return p

def plot_asian_option_price(N):
     #plot asian option price as a function of N
     #N is a list of numbers of simulations
     p = np.array([])
     for n in N:
          p = np.append(p, asian_option_price(n))
     figure()
     plot(N, p, 'go-', xlabel = 'N simulation', p = 'Asian Option Price', 
                    title = 'Asian Option Price as N changes', 
                    savefig = 'asian_option_price_n.pdf')

def plot_asian_option_price_error(N):
     N_max = np.max(N)                  #select the maximum of the N
     p_max = asian_option_price(N_max)  #compute the price for the maximum N
     p = np.array([])
     errors = np.array([])
     for n in N:
          p1 = asian_option_price(n)
          errors = np.append(errors, abs(p1 - p_max))
          #using the p corresponding to the maximum N 
          #as the right value of the price
          p = np.array(p, p1)
     figure()
     #plot the N as x axis and errors as y axis
     hold('on')
     #plot curve c/sqrt(N), let c be 1, 2 ,3, 4, 5
     for i in xrange(1, 60, 10):
          error_curve = float(i) / np.sqrt(N)
          plot(N, error_curve, legend = '%d/sqtr(N)' % i)
     plot(N, errors,'b*--', xlabel = 'N simulation', ylabel = 'errors', 
               title = 'errors as N increases', 
               savefig = 'price_errors.pdf')
     hold('off')

if __name__ == '__main__':
     N = range(1000, 5050, 100)
     plot_asian_option_price(N)
     plot_asian_option_price_error(N)
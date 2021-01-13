#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

n = 21
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 19170307
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

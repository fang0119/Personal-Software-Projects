// Python script used to complete Challenge 2, again making use of the "Requests" library



import requests

def reverse_string(originalString): ## this function takes in a string and returns it in reverse order
    reversed_string = ''
    index = len(originalString)
    while index:
        index -= 1                   
        reversed_string += originalString[index]
    return reversed_string
    
r = requests.post('http://challenge.code2040.org/api/reverse',json = { 'token': '16f6075adf4d9f4d209314475bc27e4b' })

inputString = r.text

reversedString = reverse_string(inputString)

requests.post('http://challenge.code2040.org/api/reverse/validate',json = { 'token': '16f6075adf4d9f4d209314475bc27e4b' , 'string' : reversedString})

// Python Script used to complete Challenge 3, using the Requests library to facilitate communication with the API

import requests

r = requests.post('http://challenge.code2040.org/api/haystack', json = { 'token': '16f6075adf4d9f4d209314475bc27e4b' })

inputDict = r.json()

needleString = inputDict['needle']

haystackArray = inputDict['haystack']

index = -1
match = False

while (match == False):
    index += 1
    match = haystackArray[index] == needleString
    
needle = index

print(needle)

r = requests.post('http://challenge.code2040.org/api/haystack/validate', json = { 'token': '16f6075adf4d9f4d209314475bc27e4b', 'needle' : needle })

print(r.text) ##prints the API's response, confirming that the delivery of the json was successful

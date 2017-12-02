//Python Code for the completion of Challenge 4, using the 'Requests' library to facilitate communication with the Code 2040 Fellows API

import requests

r = requests.post('http://challenge.code2040.org/api/prefix',
                   json = { 'token': '16f6075adf4d9f4d209314475bc27e4b' })

inputDict = r.json()

targetPrefix = inputDict['prefix']
testArray = inputDict['array']
targetArray = []

index = 0

while (index <= 19):  
    if ((testArray[index])[0:4] != targetPrefix): 
        targetArray.append(testArray[index])
    index+=1

r = requests.post('http://challenge.code2040.org/api/prefix/validate',
                   json = { 'token': '16f6075adf4d9f4d209314475bc27e4b',
                            'array': targetArray})

// Python Script used to complete Challenge 5

import requests

r = requests.post('http://challenge.code2040.org/api/dating',
                   json = { 'token': '16f6075adf4d9f4d209314475bc27e4b' })

inputDict = r.json()
interval = inputDict['interval']
datestamp = inputDict['datestamp']

year = (int)(datestamp[0:4])
month = (int)(datestamp[5:7])
day = (int)(datestamp[8:10])
hour = (int)(datestamp[11:13])
minute = (int)(datestamp[14:16])
second = (int)(datestamp[17:19]) 

timeDelta = interval

deltaDays = interval//86400

deltaRemainder = interval - deltaDays*86400

deltaHours = deltaRemainder//3600

deltaRemainder = deltaRemainder - deltaHours*3600

deltaMinutes = deltaRemainder//60

deltaRemainder = deltaRemainder - deltaMinutes*60

deltaSeconds = deltaRemainder

finalDay = (str)(day + deltaDays)

finalHour = (str)(hour + deltaHours)

finalMinute = (str)(minute + deltaMinutes)

finalSecond = (str)(second + deltaSeconds)

if ((second + deltaSeconds) > 59):
    finalMinute = (str)(minute + deltaMinutes + 1)

    finalSecond = (str)(second + deltaSeconds - 60)

if ((minute + deltaMinutes) > 59):
    finalHour = (str)(hour + deltaHours + 1)

    finalMinute = (str)(minute + deltaMinutes - 60)

if ((hour + deltaHours) > 24):
    finalDay = (str)(day + deltaDays + 1)

    finalHour = (str)(hour + deltaHours - 24)


if ((day + deltaDays) < 10): finalDay = ('0'+ finalDay)

if ((hour + deltaHours) < 10): finalHour = ('0'+ finalHour)

if ((minute + deltaMinutes) < 10): finalMinute = ('0' + finalMinute)

if ((second + deltaSeconds) < 10): finalSecond = ('0' + finalSecond)

targetDateStamp = datestamp[0:8] + finalDay + 'T' + finalHour + ':' + finalMinute + ':' + finalSecond + 'Z'

r = requests.post('http://challenge.code2040.org/api/dating/validate',
                   json = { 'token': '16f6075adf4d9f4d209314475bc27e4b',
                            'datestamp' : targetDateStamp})

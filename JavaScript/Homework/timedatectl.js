let child = require('child_process')

const timedate = (callback) =>
  child.exec('timedatectl', (err, stdout, stderr) =>
    err ? callback(err) : callback(null, stdout.toString().split('\n').filter(l => l.length)
      .reduce((prev, curr) => {
        let pair = curr.split(': ').map(str => str.trim())
        prev[pair[0]] = pair[1]
        return prev
      }, {})))

timedate((err,out) => console.log(out))

/*
{ 'Local time': 'Tue 2016-11-15 18:21:28 CST',
  'Universal time': 'Tue 2016-11-15 10:21:28 UTC',
  'RTC time': 'Tue 2016-11-15 10:21:27',
  'Time zone': 'Asia/Shanghai (CST, +0800)',
  'Network time on': 'yes',
  'NTP synchronized': 'yes',
  'RTC in local TZ': 'no' }
*/

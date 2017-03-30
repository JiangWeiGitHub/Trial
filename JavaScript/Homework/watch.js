let fs = require('fs')

fs.watch('/home/wisnuc/Documents', (eventType, filename) => {

  console.log(`event type is: ${eventType}`)

  if (filename) {
    console.log(`filename provided: ${filename}`)
  }
  else {
    console.log('filename not provided')
  }
})

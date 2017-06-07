let former = (funcName) => {console.log("Former Get From Latter: " + funcName)}

let latter = (string) => {console.log("Latter Contents: " + string);return "I'm latter"}

former(latter("hello world"))

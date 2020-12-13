package main

   import (
       "os/exec"
       "fmt"
       "strconv"
   )

   func main() {
       cmd := exec.Command("sudo", "python3","/home/pi/workspace/empty.py")
       outputn, errn := cmd.Output()
       if (errn != nil) {
           fmt.Println(errn)
       }
       output, err := strconv.ParseFloat(outputn[:len(outputn)-1])

       if (err != nil) {
           fmt.Println(err)
       }
       fmt.Println(string(output))
   }

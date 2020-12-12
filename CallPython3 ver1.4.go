package main

   import (
       "os/exec"
       "fmt"
       "strconv"
   )
   func main() {
       outputn, err := exec.Command("sudo", "python","/home/pi/workspace/getdata.py").Output()
       if (err != nil) {
           fmt.Println(err)
       }
       output := string(outputn[:len(outputn)-1])
       outputf, errf := strconv.ParseFloat(output, 64)
       if (errf != nil) {
          fmt.Println(err)
       }
       fmt.Println(outputf)
   }

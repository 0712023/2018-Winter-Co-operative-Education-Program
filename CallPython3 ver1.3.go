package main

   import (
       "os/exec"
       "fmt"
       "strconv"
   )
   func main() {
       cmd := exec.Command("sudo", "python3","/home/pi/workspace/empty.py")
       outputn, err := cmd.Output()
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

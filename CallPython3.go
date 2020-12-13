package main

   import (
       "os/exec"
       "fmt"
   )

   func main() {
       cmd := exec.Command("sudo", "python3","/home/pi/workspace/empty.py")
       outputn, err := cmd.Output()
       output := string(outputn[:len(outputn)-1])
       if (err != nil) {
           fmt.Println(err)
       }
       fmt.Println(string(output))
   }

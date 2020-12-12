package main

   import (
       "os/exec"
       "fmt"
   )

   func main() {
       cmd := exec.Command("sudo", "python3","/home/pi/workspace/empty.py")
       output, err := cmd.CombinedOutput()

       if (err != nil) {
           fmt.Println(err)
       }
       fmt.Println(string(output))
   }

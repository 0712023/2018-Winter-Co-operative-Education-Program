package main

   import (
       "os/exec"
       "fmt"
       "strconv"
   )
   func main() {
	outputt, err := exec.Command("sudo", "python", "/home/pi/workspace/getdata.py", "1").Output()
	if (err != nil) {
			fmt.Println(err)
	}
	temp, errt := strconv.ParseFloat(string(outputt[:len(outputt)-1]), 64)
	if (errt != nil) {
		 fmt.Println(errt)
	}

	settingt, errs :=exec.Command("sudo", "python", "/home/pi/workspace/getdata.py", "2").Output()
	if (errs != nil) {
			fmt.Println(errs)
	}
	setting, errf := strconv.ParseFloat(string(settingt[:len(settingt)-1]), 64)
	if (errf != nil) {
		 fmt.Println(err)
	}
	data := []float64{}
	data = append(data, temp, setting)
	fmt.Println(data)
}

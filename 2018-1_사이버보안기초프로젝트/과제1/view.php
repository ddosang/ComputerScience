<?php
	if($_SERVER["REQUEST_METHOD"]=="POST"){
		$conn=mysqli_connect("localhost", "root", "", "idtest");
		if(!$conn){
			die("Connection failed: ".mysqli_connect_error());
		}
		$password=$_POST["password"];
		$token=hash('sha512', $password);
		$sql="SELECT PWD FROM users WHERE ID='".$_POST["id"]."'";
		$result=mysqli_query($conn, $sql);
		if($result){
			while($row=mysqli_fetch_array($result)){
				if($row["PWD"]==$token){
					echo "인증 성공";
				} else{
					echo "인증 실패";
				}
			}
		} else{
			echo "Result Failed";
		}
		mysqli_close($conn);
	}
	
?>

<?php
if(!isset($_COOKIE['person'])) {    //no cookie set
   setcookie('person', '21',86400);
}
else{
 $tempID = $_COOKIE['person'];  //load cookie data
}

if( isset($_POST['updatedName']) ){    //loaded from redirect
    $tempID = $_POST["updatedName"];
    setcookie('person', $tempID,86400);
}
else if(!isset($_COOKIE['person'])) {   //no cookie set
    $tempID = $_COOKIE['person'];
}
else{
    $tempID = 21; //start with H. Harrington if no cookie
}

?>
<html>
<style>
body{
font-size:16px;
font-family:garamond;
background-image: url("5023.png");
}
.buttonpar{ 
    background-color: #008CBA; /* Blue */
  border: none;
  color: white;
  padding: 8px 12px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 12px;
  box-shadow: 0 8px 16px 0 rgba(0,0,0,0.2), 0 6px 20px 0 rgba(0,0,0,0.19);
}
.buttonspo{ 
    background-color: #f44336; /* Red */
  border: none;
  color: white;
  padding: 8px 12px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 12px;
  box-shadow: 0 8px 16px 0 rgba(0,0,0,0.2), 0 6px 20px 0 rgba(0,0,0,0.19);
}
.buttonchi{
    background-color: #4CAF50; /* Green */
  border: none;
  color: white;
  padding: 8px 12px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 12px;
  box-shadow: 0 8px 16px 0 rgba(0,0,0,0.2), 0 6px 20px 0 rgba(0,0,0,0.19);
}
h4 {
    margin-top: 8px;
  margin-bottom: 6px;
}
h3 {
    margin-top: 36px;
 margin-bottom: 6px;
}

</style>
<?php


$dbServername = "sql112.epizy.com";
$dbUsername = "epiz_32629197";
$dbPassword = "Dogbane1";
$dbName = "epiz_32629197_tree";
$topline="";
if(isset($_COOKIE['person'])){
$currentID = $_COOKIE['person'];  //get the initial person to view, or set to default
}
else{
$currentID = 21;
}
if (!$conn = mysqli_connect($dbServername, $dbUsername, $dbPassword, $dbName)){
die ("Failed to connect");
}?>


<?php
$sql = "SELECT * FROM tree WHERE id='$currentID'";    //Get initial info about selected person
$result = mysqli_query($conn, $sql);
if (mysqli_num_rows($result) > 0) {
     while($row = mysqli_fetch_assoc($result)) { 
        $spouseID = $row["spouse"];
        $fatherID = $row["father"];
        $motherID = $row["mother"];
        $siblingID = $row["sibling"];
        $childID = $row["child"];
        $first = $row["first"];
        $middle = $row["middle"];
        $last = $row["last"];
        $birth = $row["birth"];
        $death = $row["death"];
        $pic = $row["photo"];
        $pic = "/pictures/" . $pic;  //concat picture name to correct folder        
	   ?><br><?php    
      
    }
}
  ?><h1>Parents</h1><?php
 $sql = "SELECT * FROM tree WHERE id=$fatherID";      //FATHER
$result = mysqli_query($conn, $sql);
if (mysqli_num_rows($result) > 0) {
     while($row = mysqli_fetch_assoc($result)) { 
	    ?><h3><?php echo $row["first"] . "&nbsp" . $row["middle"] . "&nbsp" . $row["last"];?><br></h3><h4>
        Born:<?php echo "&nbsp" . $row["birth"];?><br>
        Died:<?php echo "&nbsp" .  $row["death"];?><br></h4><?php
        $tempName= $row["first"];
        $tempID = $row["id"];
    }
}?>
<form action="test.php" method="POST">
<input type="hidden" name="updatedName" value="<?php echo $tempID;?>">
<input type="submit" class="buttonpar" value="View <?php echo $tempName;?>">
</form>
<?php
$sql = "SELECT * FROM tree WHERE id=$motherID";      //MOTHER
$result = mysqli_query($conn, $sql);
if (mysqli_num_rows($result) > 0) {
     while($row = mysqli_fetch_assoc($result)) { 
	    ?><h3><?php echo $row["first"] . "&nbsp" . $row["middle"] . "&nbsp" . $row["last"];?><br></h3><h4>
        Born:<?php echo "&nbsp" . $row["birth"];?><br>
        Died:<?php echo "&nbsp" .  $row["death"];?><br></h4><?php
        $tempName= $row["first"];
        $tempID = $row["id"];

        ?>
<form action="test.php" method="POST">
<input type="hidden" name="updatedName" value="<?php echo $tempID;?>">
<input type="submit" class="buttonpar" value="View <?php echo $tempName;?>">
</form><?php
    }
}
?><hr class="rounded">
<?php if ($pic!=NULL){          //display picture
    if ($pic!="/pictures/"){?> 
        <img src=<?php echo $pic;?> width="250px"><?php //only load picture if one exists
    }
}

?><br>

<h3><?php echo $first . "&nbsp" . $middle . "&nbsp" .$last;?><br></h3><h4>
        Born:<?php echo "&nbsp" . $birth;?><br>
        Died:<?php echo "&nbsp" .  $death;?><br></h4><?php
 $sql = "SELECT * FROM tree WHERE id=$spouseID";    //SPOUSE
$result = mysqli_query($conn, $sql);
if (mysqli_num_rows($result) > 0) {
     while($row = mysqli_fetch_assoc($result)) { 
	    ?><h3><?php echo $row["first"] . "&nbsp" . $row["middle"] . "&nbsp" . $row["last"];?></h3><h4>
        Born:<?php echo "&nbsp" . $row["birth"];?><br>
        Died:<?php echo "&nbsp" .  $row["death"];?><br></h4><?php
        $tempName= $row["first"];
        $tempID = $row["id"];
        ?>
<form action="test.php" method="POST">
<input type="hidden" name="updatedName" value="<?php echo $tempID;?>">
<input type="submit" class="buttonspo" value="View <?php echo $tempName;?>">
</form><?php
    }
}

?><hr class="rounded">
<?php
$moreSiblings = true;?>
<h1>Children</h1><?php

while ($moreSiblings){ //keep going if more siblings
        $sql = "SELECT * FROM tree WHERE id=$childID";      //CHILD
        $result = mysqli_query($conn, $sql);

            if (mysqli_num_rows($result) > 0) {
                while($row = mysqli_fetch_assoc($result)) { 
                    ?><h3><?php echo $row["first"] . "&nbsp" . $row["middle"] . "&nbsp" . $row["last"];?></h3><h4>
                    Born:<?php echo "&nbsp" . $row["birth"];?><br>
                    Died:<?php echo "&nbsp" .  $row["death"];?></h4><?php
                    if ($row["sibling"]>0){
                                $moreSiblings = true;
                                $childID = $row["sibling"];
                    }
                    else $moreSiblings = false;            
                $tempName= $row["first"];
                $tempID = $row["id"];

                ?>
                <form action="test.php" method="POST">
                <input type="hidden" name="updatedName" value="<?php echo $tempID;?>">
                <input type="submit" class="buttonchi" value="View <?php echo $tempName;?>">
                </form><?php
                    }
                 
            }
            else{
                break;   //end list after last sibling found
            }           
}?>

</html>


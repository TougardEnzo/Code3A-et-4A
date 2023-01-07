function verification()
{
    if(document.getElementById("nom").value !="")
    {
        if(document.getElementById("prenom").value !="")
        {
            if(document.getElementById("email").value != "")
            {
                if(document.getElementById("portable").value != "")
                {
                    if(document.getElementById("adresse").value != "")
                    {
                        if(document.getElementById("yes") == false && document.getElementById("no") == false)
                        {
                            alert("wrong input no checkbox checked for VIP");
                        }
                        else
                        {
                            if(document.getElementById("hobby") == false && document.getElementById("hobby2") == false && document.getElementById("hobby3") == false)
                            {
                                alert("wrong input for hobby no hobby checked");
                            }
                            else
                            {
                                document.location = "last.html";
                            }
                        }
                    }
                    else
                    {
                        alert("wrong input for adresse");
                    }
                }
                else
                {
                    alert("wrong input for portable");
                }
            }
            else
            {
                alert("wrong input for email");
            }
        }
        else
        {
            alert("wrong input for prenom");
        }
    }
    else
    {
        alert("wrong input for name");
    }
}
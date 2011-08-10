
function fadeMainView(view)
{
    if (view == mainViewOpacity)
        return;

    fadeA.running = true;
    fadeB.running = true;
    if (mainViewOpacity == 1)
    {
        mainViewOpacity = 0;
    }
    else
    {
        mainViewOpacity = 1;
    }

}

function func() {

}

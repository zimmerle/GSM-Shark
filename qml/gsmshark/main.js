
function switchMainView(view)
{
    if (view == views.selectedView)
        return;


    if (views.selectedView == 1)
    {
        views.selectedView = 0;
    }
    else
    {
        views.selectedView = 1;
    }

    switchViews.running = true;
}


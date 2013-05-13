<?xml version="1.0"?>
<recipe>
    <merge from="AndroidManifest.xml.ftl" />

    <instantiate from="res/menu/main.xml.ftl"
            to="res/menu/${menuName}.xml" />

    <merge from="res/values/strings.xml.ftl" />

    <merge from="res/values/dimens.xml" />
    <merge from="res/values-sw600dp/dimens.xml" />
    <merge from="res/values-sw720dp-land/dimens.xml" />

    <!-- Decide what kind of layout to add (viewpager or not) -->
    <#if navType?contains("pager")>
        <instantiate from="res/layout/activity_pager.xml.ftl"
                       to="res/layout/${layoutName}.xml" />
        <instantiate from="res/layout/fragment_dummy.xml.ftl"
                       to="res/layout/fragment_${classToResource(activityClass)}_dummy.xml" />

    <#elseif navType == "tabs" || navType == "dropdown">
        <instantiate from="res/layout/activity_fragment_container.xml"
                     to="res/layout/${layoutName}.xml" />
        <instantiate from="res/layout/fragment_dummy.xml.ftl"
                       to="res/layout/fragment_${classToResource(activityClass)}_dummy.xml" />

    <#else>
        <instantiate from="res/layout/activity_simple.xml.ftl"
                     to="res/layout/${layoutName}.xml" />
    </#if>

    <!-- Decide which activity code to add -->
    <#if navType == "none">
        <instantiate from="src/app_package/SimpleActivity.java.ftl"
                       to="${srcOut}/${activityClass}.java" />

    <#elseif navType == "tabs_pager" || navType == "pager_strip">
        <instantiate from="src/app_package/TabsAndPagerActivity.java.ftl"
                       to="${srcOut}/${activityClass}.java" />

    <#elseif navType == "tabs">
        <instantiate from="src/app_package/TabsActivity.java.ftl"
                       to="${srcOut}/${activityClass}.java" />

    <#elseif navType == "dropdown">
        <instantiate from="src/app_package/DropdownActivity.java.ftl"
                       to="${srcOut}/${activityClass}.java" />

    </#if>

    <open file="res/layout/${layoutName}.xml" />
</recipe>

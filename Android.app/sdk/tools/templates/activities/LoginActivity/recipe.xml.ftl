<?xml version="1.0"?>
<recipe>
    <merge from="AndroidManifest.xml.ftl" />

    <merge from="res/values/styles.xml" />
    <merge from="res/values-large/styles.xml" />
    <copy from="res/menu/activity_login.xml"
            to="res/menu/${menuName}.xml" />
    <instantiate from="res/layout/activity_login.xml.ftl"
                   to="res/layout/${layoutName}.xml" />

    <instantiate from="res/values/strings.xml.ftl"
                   to="res/values/strings_${simpleName}.xml" />

    <instantiate from="src/app_package/LoginActivity.java.ftl"
                   to="${srcOut}/${activityClass}.java" />

    <open file="res/layout/${layoutName}.xml" />
</recipe>

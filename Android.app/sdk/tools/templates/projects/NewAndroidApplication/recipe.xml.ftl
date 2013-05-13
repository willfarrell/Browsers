<?xml version="1.0"?>
<recipe>
    <instantiate from="AndroidManifest.xml.ftl" />

<#if copyIcons>
    <copy from="res/drawable-hdpi" />
    <copy from="res/drawable-mdpi" />
    <copy from="res/drawable-xhdpi" />
</#if>
    <instantiate from="res/values/styles.xml.ftl" />
<#if buildApi gte 11 && baseTheme != "none">
    <instantiate from="res/values-v11/styles_hc.xml.ftl"
                   to="res/values-v11/styles.xml" />
</#if>
<#if buildApi gte 14 && baseTheme?contains("darkactionbar")>
    <copy from="res/values-v14/styles_ics.xml"
            to="res/values-v14/styles.xml" />
</#if>

    <instantiate from="res/values/strings.xml.ftl" />
</recipe>
